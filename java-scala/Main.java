public class Main {
  public static void main(String[] args) {
    long[] seed = new long[6];
    for (int i=0; i<6; i++) {
      seed[i] = i+1;
    }
    RNG gen = new RNG(seed);
    for (int i=0; i<10; i++) {
      System.out.println(gen.next());
    }
  }
}