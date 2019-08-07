import scala.math.sqrt;
object main {
  val length: Int = 100000;
  def main(args: Array[String]) {
    // generate 100000 random numbers
    val seed: Array[Long] = Array.iterate(1L, 7)(x => x+1);
    val gen: RNG = new RNG(seed);
    val data: Array[Double] = (new Array[Double](length)).map {case (_) => gen.next()};

    // sort data
    val sorted = data.sorted;

    // perform ks test
    val baseline: Array[Int] = Array.range(0, length);
    val baselinemin: Array[Double] = baseline.map {case (x) => x.toDouble/length}
    val baselinemax: Array[Double] = baseline.map {case (x) => (1+x.toDouble)/length}

    val diffmin = sorted.zip(baselinemin).map {case (x, y) => x - y};
    val diffmax = sorted.zip(baselinemax).map {case (x, y) => y - x};

    val max1 = diffmin.max;
    val max2 = diffmax.max;

    val d = if (max1 > max2) max1 else max2;
    println("D\t" + d);
    val dbase = 2/sqrt(length);
    println("D base\t" + dbase);
  }
}
