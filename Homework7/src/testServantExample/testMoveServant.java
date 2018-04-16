package testServantExample;

import ServantExample.*;
import org.junit.jupiter.api.Assertions;

class testMoveServant {

    MoveServant service = new MoveServant();
    @org.junit.jupiter.api.Test
    void walk() {
       Ant ant  = new Ant(Direction.UP);
       FastAnt fast = new FastAnt(Direction.LEFT);
       Slug slug = new Slug(Direction.DOWN);
       service.walk(ant);
       service.walk(fast);
       service.walk(slug);
       Position expAntPos = new Position();
       expAntPos.setPosition(0, 1);
       Position expFastAntPos = new Position();
       expFastAntPos.setPosition(-5, 0);
       Position expSlugPos = new Position();
       expSlugPos.setPosition(0, -1);
       Assertions.assertEquals(expAntPos, ant.getPosition());
       Assertions.assertEquals(expFastAntPos, fast.getPosition());
       Assertions.assertEquals(expSlugPos, slug.getPosition());
    }

    @org.junit.jupiter.api.Test
    void walkTo() {
        Ant ant = new Ant(Direction.DOWN);
        FastAnt fast = new FastAnt(Direction.LEFT);
        Slug slug = new Slug(Direction.UP);
        Position antPosition = new Position();
        antPosition.setPosition(5,5);
        service.walkTo(ant, antPosition);
        service.walkTo(fast, antPosition);
        service.walkTo(slug, antPosition);
        Assertions.assertEquals(ant.getPosition(), antPosition);
        Assertions.assertEquals(fast.getPosition(), antPosition);
        Assertions.assertEquals(slug.getPosition(), antPosition);
    }

    @org.junit.jupiter.api.Test
    void turnAround() {
        Ant ant = new Ant(Direction.RIGHT);
        FastAnt fast = new FastAnt(Direction.LEFT);
        Slug slug = new Slug(Direction.UP);
        service.turnAround(ant);
        service.turnAround(fast);
        service.turnAround(slug);
        Assertions.assertEquals(ant.getDirection(), Direction.LEFT);
        Assertions.assertEquals(fast.getDirection(), Direction.RIGHT);
        Assertions.assertEquals(slug.getDirection(), Direction.UP);
    }
}