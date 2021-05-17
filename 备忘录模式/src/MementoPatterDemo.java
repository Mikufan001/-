public class MementoPatterDemo {
    public static void main(String[] args){
        Originator originator = new Originator();
        CareTaker caretaker = new CareTaker();

        originator.setState("好耶1");
        originator.setState("好耶2");
        caretaker.add(originator.saveStateToMemento());
        originator.setState("好耶3");
        caretaker.add(originator.saveStateToMemento());
        originator.setState("好耶4");

        System.out.println("现在的是第几个好耶："+originator.getState());
        originator.getStateToMemento(caretaker.get(0));
        System.out.println("第一次保存的是第几个好耶："+originator.getState());
        originator.getStateToMemento(caretaker.get(1));
        System.out.println("第二次保存的是第几个好耶："+originator.getState());
    }

}
