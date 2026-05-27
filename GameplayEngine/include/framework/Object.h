#pragma once
#include "framework/Core.h"

namespace gp{
    class Object{
    public:
        Object();
        virtual ~Object();

        void Destroy();
        bool IsPendingDestroy() const {return mPendingDestroy;}

    private:
        bool mPendingDestroy;
    };
}