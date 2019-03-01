// Interfaces declarations
class IFlyable {
  public:
    virtual int fly() = 0;
};

class IRunnable {
  public:
    virtual int run() = 0;
};

class IEatable {
  public:
    virtual int eat() = 0;
};

// Concrete strategies implementation
class FlyFast : public IFlyable {
  public:
    int fly() override {
      return 2;
    }
};

class FlySlow : public IFlyable {
  public:
    int fly() override {
      return 1;
    }
};



class NoFly : public IFlyable {
  public:
    int fly() override {
      return 0;
    }
};

class RunFast : public IRunnable {
  public:
    int run() override {
      return 4;
    }
};

class RunSlow : public IRunnable {
  public:
    int run() override {
      return 1;
    }
};

class EatLots : public IEatable {
  public:
    int eat() override {
      return 3;
    }
};

class EatLittle : public IEatable {
  public:
    int eat() override {
      return 1;
    }
};