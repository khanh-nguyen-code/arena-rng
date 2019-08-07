object main {
  def main(args: Array[String]) {
    val seed: Array[Long] = Array.iterate(1L, 7)(x => x+1)
    val gen: RNG = new RNG(seed)
    for (i <- 0 until 10) {
      System.out.println(gen.next())
    }
  }
}
