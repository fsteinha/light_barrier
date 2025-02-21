#include <functional>
#include <map>


class CallbackManager
{
private:
    /* data */
    std::map<int, std::function<void()>> callbacks; // Callback functions with unique IDs
    int nextCallbackId = 0;

public:
    CallbackManager(/* args */);
    ~CallbackManager();

    //@brief: Add a send callback function
    int addCallback(std::function<void()> callback);

    //@brief: Remove a send callback function
    void removeCallback(int callbackId);

    //@brief: Execute the callback functions
    void executeCallbacks() const;

};

