class RNG {
  private[this] var a: Array[Long] = new Array[Long](4);
  private[this] var b: Array[Long] = new Array[Long](4);
  def this(seed: Array[Long]) {
    this();
    a(0) = 0;
    a(1) = seed(0) % 4294967087L;
    a(2) = seed(1) % 4294967087L;
    a(3) = seed(2) % 4294967087L;
    b(0) = 0;
    b(1) = seed(3) % 4294967087L;
    b(2) = seed(4) % 4294967087L;
    b(3) = seed(5) % 4294967087L;
  }
  def next(): Double = {
    // arena RNG
    a(0) = (1403580L*a(2) - 810728L*a(3)) % 4294967087L;
    b(0) = (527612L*b(1) - 1370589L*b(3)) % 4294944443L;
    var z: Long  = (a(0) - b(0)) % 4294967087L;
    z += (if (z < 0) 4294967087L else 0L);
    var u: Double = if (z > 0)
                      z.toDouble/4294967087L;
                    else
                      4294967087L.toDouble/4294967088L;
    a(3) = a(2);
    a(2) = a(1);
    a(1) = a(0);
    b(3) = b(2);
    b(2) = b(1);
    b(1) = b(0);

    return u;
  }
}
