class Controller {
private:
  int inputPin;
  int outputPin;
  bool the_system_is_closed;
  float G[5];
  float H[5];
  float prod[10];
  float ranges[4];


public:
  Controller(int inppin, int outpin, float g[], float h[], float Prod[],
             bool isClosed);
  virtual float zinput();
  virtual float zCalcOnce(float inp);
  virtual void zoutput(float inp);
  bool isClosed();
  bool nyquist_stability_criterion();
  void changeG(float g[]);
  void changeH(float h[]);
};
