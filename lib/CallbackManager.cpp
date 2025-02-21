#include "CallbackManager.hpp"

CallbackManager::CallbackManager(/* args */)
{
}

CallbackManager::~CallbackManager()
{
}

int CallbackManager::addCallback(std::function<void()> callback) {
    int id = nextCallbackId++;
    callbacks[id] = callback;
    return id;
}

void CallbackManager::removeCallback(int callbackId) {
    callbacks.erase(callbackId);
}

void CallbackManager::executeCallbacks() const {
    for (const auto& pair : callbacks) {
        pair.second();
    }
}
