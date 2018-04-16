package ServantExample;

public interface Movable {
    Position getPosition();
    void setPosition(Position _position);
    int getMoveSpeed();
    Direction getDirection();
    void setDirection(Direction _dir);
}
