class RNG {
  private[this] var A: Array[Long] = new Array[Long](4);
  private[this] var B: Array[Long] = new Array[Long](4);
  def this(seed: Array[Long]) {
    this();
    A(0) = 0;
    A(1) = seed(0) % 4294967087L;
    A(2) = seed(1) % 4294967087L;
    A(3) = seed(2) % 4294967087L;
    B(0) = 0;
    B(1) = seed(3) % 4294967087L;
    B(2) = seed(4) % 4294967087L;
    B(3) = seed(5) % 4294967087L;
  }
  def next(): Double = {
    // Arena RNG
    A(0) = (1403580L*A(2) - 810728L*A(3)) % 4294967087L;
    B(0) = (527612L*B(1) - 1370589L*B(3)) % 4294944443L;
    var z: Long  = (A(0) - B(0)) % 4294967087L;
    z += (if (z < 0) 4294967087L else 0L);
    var u: Double = if (z > 0)
                      z.toDouble/4294967087L;
                    else
                      4294967087L.toDouble/4294967088L;
    A(3) = A(2);
    A(2) = A(1);
    A(1) = A(0);
    B(3) = B(2);
    B(2) = B(1);
    B(1) = B(0);

    return u;
  }
}
