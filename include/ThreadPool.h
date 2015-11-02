#pragma once
#include "GppDefines.h"
#include <vector>
#include <list>

namespace GPP
{
    extern GPP_EXPORT Int GetProcessorCount();

    class MutexImpl;
    class Mutex
    {
    public:
        Mutex();
        void Lock();
        void Unlock();
        void* GetHandle();
        ~Mutex();

    private:
        MutexImpl* mpImpl;
    };

    class ScopedLock
    {
    public:
        ScopedLock(Mutex& mutex);
        ~ScopedLock();

    private:
        Mutex& mMutex;
    };

    class ConditionVariableImpl;
    class ConditionVariable
    {
    public:
        ConditionVariable();
        Int Sleep(Mutex& mutex);
        Int WakeSingle();
        Int WakeAll();
        ~ ConditionVariable();

    private:
        ConditionVariableImpl* mpImpl;
    };

    enum TaskType
    {
        TP_Exit = 0,
        TP_Normal
    };

    class TaskBase
    {
    public:
        TaskBase(TaskType tp = TP_Normal);
        virtual Int Run(void);
        virtual void OnComplete(void);
        TaskType GetType() const;
        virtual ~TaskBase();

    private:
        TaskType mTP;
    };

    class ThreadPool;
    class Thread
    {
    public:
        Thread(ThreadPool* threadPool);
        Int Start();
        Int Run();
        ~Thread();

    private:
        ThreadPool* mpThreadPool;
    };

    class ThreadPool
    {
    public:
        ThreadPool();
        Int Init(Int threadCount);
        void Clear(void);
        Int InsertTask(TaskBase* pTask);
        TaskBase* GetTask(void);
        void FinishATask(void);
        void WaitUntilAllDone();
        ~ThreadPool();

    private:
        std::vector<Thread*> mThreadList;
        std::list<TaskBase*> mTaskList;
        Mutex mMutex;
        ConditionVariable mGetTaskCV;
        ConditionVariable mFinishTaskCV;
        Int mTaskLeftCount;
    };
}
