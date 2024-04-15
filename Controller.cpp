float Controller ::zinput() { return analogRead(inputPin); }
float Controller ::zCalcOnce(float inp) {
  return G[0] + G[1] * inp + G[2] * inp * inp + G[3] * inp * inp * inp +
         G[4] * inp * inp * inp * inp;
}

void Controller ::zoutput(float inp) {
  float to_output = H[0] + H[1] * inp + H[2] * inp * inp +
                    H[3] * inp * inp * inp + H[4] * inp * inp * inp * inp;
  to_output = constrain(to_output, ranges[2], ranges[3]);
  analogWrite(outputPin, to_output);
}

void Controller ::changeG(float g[]) {
  G[0] = g[0];
  G[1] = g[1];
  G[2] = g[2];
  G[3] = g[3];
  G[4] = g[4];
}

void Controller ::changeH(float h[]) {
  H[0] = h[0];
  H[1] = h[1];
  H[2] = h[2];
  H[3] = h[3];
  H[4] = h[4];
}

bool Controller::isClosed() { return the_system_is_closed; }

bool Controller ::nyquist_stability_criterion() {
  if (!the_system_is_closed) {
    return true;
  } else {
    for (int j = 0; j < 10; j++) {
      if (zeros_of_prod_plus_1[j][0] > 0) {
        return false;
      }
    }
    return true;
  }
}
