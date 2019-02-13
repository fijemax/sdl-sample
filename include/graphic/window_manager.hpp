#ifndef WINDOWS_MANAGER_HPP
#define WINDOWS_MANAGER_HPP

#include <string>

using std::string;

/**
 * WindowManager
 */
class WindowManager
{
  public:
    WindowManager(std::string *assetsPath) : mAssetsPath(assetsPath), mRun(false) {}
    ~WindowManager(){};

    int init();
    int display();
    bool isRunning()
    {
        return mRun;
    }

  private:
    string *mAssetsPath;
    bool mRun;
};

#endif // WINDOWS_MANAGER_HPP