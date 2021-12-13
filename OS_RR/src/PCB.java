import java.util.ArrayList;
import java.util.List;

public class PCB {
    private String pName;
    private List pInstructions = new ArrayList();
    private int CurrentInstruction;

    public PCB() {
    }

    public String getpName() {
        return this.pName;
    }

    public void setpName(String pName) {
        this.pName = pName;
    }

    public int getCurrentInstruction() {
        return this.CurrentInstruction;
    }

    public void setCurrentInstruction(int currentInstruction) {
        this.CurrentInstruction = currentInstruction;
    }

    public List<Instructions> getpInstructions() {
        return this.pInstructions;
    }

    public void setpInstructions(List<Instructions> pInstructions) {
        this.pInstructions = pInstructions;
    }
}
