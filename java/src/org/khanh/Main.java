package org.khanh;

public class Main {

    public static void main(String[] args) {
        RNG rng = new ArenaRNG(new long[]{1, 2, 3, 4, 5, 6});
        for (int i=0; i<10; i++) {
            System.out.println(rng.Next());
        }
    }
}
