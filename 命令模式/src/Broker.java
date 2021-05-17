import java.util.ArrayList;
import java.util.List;

public class Broker {
    private List<Order> orderlist = new ArrayList<>();

    public void takeOrder(Order order){
        orderlist.add(order);
    }

    public void placeOrders(){
        for(Order order : orderlist){
            order.execute();
        }
        orderlist.clear();
    }
}
