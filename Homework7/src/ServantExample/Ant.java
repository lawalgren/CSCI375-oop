package ServantExample;

public class Ant implements Movable {
    private Direction dir;
    private Position pos = new Position();

    public Ant(Direction _dir) {
        dir = _dir;
    }

    @Override
    public void setDirection(Direction _dir) {
        dir = _dir;
    }

    @Override
    public Position getPosition() {
        return pos;
    }

    @Override
    public void setPosition(Position _position) {
       pos = _position;
    }

    @Override
    public int getMoveSpeed() {
        return 1;
    }

    @Override
    public Direction getDirection() {
        return dir;
    }
}
