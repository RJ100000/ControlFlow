class Controller {
private:
  int inputPin;
  int outputPin;
  bool the_system_is_closed;
  float G[5];
  float H[5];
  float zeros_of_prod_plus_1[10][2];//[2] is for complex, real and then imaginary
  float ranges[4];
  int m;
  int n;

public:
  Controller(int inppin, int outpin, float g[], float h[], float Prod_z[],
             bool isClosed);
  virtual float zinput();
  virtual float zCalcOnce(float inp);
  virtual void zoutput(float inp);
  bool isClosed();
  bool nyquist_stability_criterion();
  void changeG(float g[]);
  void changeH(float h[]);
};
