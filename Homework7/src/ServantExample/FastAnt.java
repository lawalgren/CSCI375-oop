package ServantExample;

public class FastAnt implements Movable {

    private Direction dir;
    private Position position;

    public FastAnt(Direction _dir) {
       dir = _dir;
    }

    @Override
    public Position getPosition() {
        return position;
    }

    @Override
    public void setPosition(Position _pos) {
        position = _pos;
    }

    @Override
    public int getMoveSpeed() {
        return 5;
    }

    @Override
    public Direction getDirection() {
        return dir;
    }

    @Override
    public void setDirection(Direction _dir) {
        dir = _dir;
    }
}
