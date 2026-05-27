#include "framework/Object.h"

namespace gp{
    Object::Object()
    : mPendingDestroy{false}
    {}

    Object::~Object(){}

    void Object::Destroy(){
        mPendingDestroy = true;
    }
}