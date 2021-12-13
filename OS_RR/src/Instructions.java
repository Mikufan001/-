import java.util.Iterator;

public class Instructions {
    private char IName;
    private double IRuntime;
    private double IRemainTime;

    public Instructions() {
    }

    public char getIName() {
        return this.IName;
    }

    public void setIName(char IName) {
        this.IName = IName;
    }

    public void setIRuntime(double IRuntime) {
        this.IRuntime = IRuntime;
    }

    public double getIRuntime() {
        return this.IRuntime;
    }

    public void setIRemainTime(double IRemainTime) {
        this.IRemainTime = IRemainTime;
    }

    public double getIRemainTime() {
        return this.IRemainTime;
    }

    public void subIRemainTime() {
        this.setIRemainTime(this.getIRemainTime() - 1.0D);
    }
}
