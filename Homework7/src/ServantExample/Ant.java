package ServantExample;

public class Ant {
    private int id;
    private Direction dir;
    static int numants = 0;
    Ant() {
       id = numants;
       numants += 1;
    }
    public void setDirection(Direction _dir) {
        dir = _dir;
    }
    public int getId() {
        return id;
    }
}
