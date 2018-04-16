package ServantExample;

public class MoveServant {
    public void walk(Movable serviced) {
        int xpos = serviced.getPosition().xposition;
        int ypos = serviced.getPosition().yposition;
        int speed = serviced.getMoveSpeed();
        Position pos = new Position();
        if (serviced.getDirection() == Direction.LEFT)
            xpos -= speed;
        else if (serviced.getDirection() == Direction.RIGHT)
            xpos += speed;
        else if (serviced.getDirection() == Direction.UP)
            ypos += speed;
        else
            ypos -= speed;
        pos.xposition = xpos;
        pos.yposition = ypos;
    }
    public void walkTo(Movable serviced, Position position) {
        serviced.setPosition(position);
    }
    public void turnAround(Movable serviced) {
        if (serviced.getDirection() == Direction.LEFT)
            serviced.setDirection(Direction.RIGHT);
        else
            serviced.setDirection(Direction.LEFT);
    }
}
