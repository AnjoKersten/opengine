#ifndef RANDOM_H
#define RANDOM_H

class Random {
public:
  Random();
  Random(long seed);
  virtual ~Random();
  double nextGaussian();
  void setSeed(long seed);
  int next(int bits);
  void nextBytes(byte[] bytes);
  int nextInt();
  int nextInt(int n);
  long nextLong();
  bool nextBoolean();
  float nextFloat();
  double nextDouble();
  double nextGaussian();

private:
  bool haveNextNextGaussian;
  double nextNextGaussian;
  long seed;
  static long final serialVersionUID = 3905348978240129619L;

};

#endif
