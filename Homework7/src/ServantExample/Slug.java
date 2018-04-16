package ServantExample;

public class Slug implements Movable{

    private Position  position;
    private Direction dir;

    public Slug(Direction _dir) {
        dir = _dir;
    }

    @Override
    public Position getPosition() {
        return position;
    }

    @Override
    public void setPosition(Position _position) {
        position = _position;
    }

    @Override
    public int getMoveSpeed() {
        return 1;
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
