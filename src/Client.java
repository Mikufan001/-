public class Client {
    public static void main(String[] args){
        Leader objDirector,objManager,objGeneralManager;

        objDirector = new Director("张三");
        objManager = new Manager("李四");
        objGeneralManager = new GeneralManager("王五");

        objDirector.setSuccessor(objManager);
        objManager.setSuccessor(objGeneralManager);

        LeaveRequest lr1 = new LeaveRequest("A",1);
        objDirector.handleRequest(lr1);

        LeaveRequest lr2 = new LeaveRequest("B",10);
        objDirector.handleRequest(lr2);

        LeaveRequest lr3 = new LeaveRequest("C",100);
        objDirector.handleRequest(lr3);


    }
}
