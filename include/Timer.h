#ifndef ALLHEADERS_HEADER
#define ALLHEADERS_HEADER
  #include "AllHeaders.h"
#endif

#ifndef TIMER_HEADER
#define TIMER_HEADER

class Timer{
  private:
    float time;
  public:
    Timer();
  public:
    void Update(float dt);
  public:
    void Restart();
  public:
    float Get();
};

#endif
