package ServantExample;

public class Position {
    public int xposition;
    public int yposition;
    public Position() {
        xposition = 0;
        yposition = 0;
    }
    public void setPosition(int _xposition, int _yposition) {
        xposition = _xposition;
        yposition = _yposition;
    }

    @Override
    public boolean equals(Object o) {
      if (o instanceof Position) {
          Position pos = (Position) o;
          return pos.yposition == yposition && pos.xposition == xposition;
    }
    return false;
}
}
