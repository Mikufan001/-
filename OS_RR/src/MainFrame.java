import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.ArrayList;

import static java.lang.Double.parseDouble;
import static java.lang.Thread.sleep;
import static javax.swing.WindowConstants.DISPOSE_ON_CLOSE;

public class MainFrame {
    private JButton bFIle, bStart, bStop;//三个按钮
    private JTextField tTime, tCur;
    private JTextArea tAll, tReady, tInput, tOutput, tWait;//队列文本域显示
    private File file;
    private JLabel lInfo;

    private ArrayList<PCB> allQue = new ArrayList<PCB>(); //初始队列
    private ArrayList<PCB> readyQue = new ArrayList<PCB>();//就绪队列
    private ArrayList<PCB> inQue = new ArrayList<PCB>(); //输入队列
    private ArrayList<PCB> outQue = new ArrayList<PCB>(); //输出队列
    private ArrayList<PCB> waitQue = new ArrayList<PCB>(); //等待队列



    private volatile Thread blinker;
    private long count = 0;

    public MainFrame() {
        //初始化界面
        init();
        //选择文件
        bFIle.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                chooseFile();
                readFile();
                saveLog("读取文件成功!\r\n________________________\r\n");
                showAll(allQue);

            }
        });

        //开始按钮对应的事件监听程序
        bStart.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                //初始队列为空即报错.
                if (allQue.size()==0) {
                    JOptionPane.showMessageDialog(null, "请重新选择文件!", "提示", JOptionPane.INFORMATION_MESSAGE);
                    return;
                }
                //输入的时间片合法-->1、初始化队列-->2、开始运行.
                if (boolTTime()) {
                    initQue();
                    startRun();

                }
            }

        });

        //停止按钮对应的事件监听程序.
        bStop.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                bStart.setText("继续调度");
                blinker = null;
            }
        });
    }

    //日志记录功能方法(将数据保存至项目路径下的log.txt文件中.)
    private void saveLog(String str) {
        File file = new File("log.txt");
        try {//创建文件
            if (!file.exists()) {
                file.createNewFile();
            }
            FileInputStream in = new FileInputStream("log.txt");         //输入流
            byte[] b = new byte[1024]; //byte数组——容器
            int i;   //长度
            StringBuilder wenzi = new StringBuilder();  //字符串变量接收文件内容
            while ((i = in.read(b)) > 0) {  //循环读取
                wenzi.append(new String(b, 0, i));  //获得文件中的内容
            }
            in.close();
            wenzi.append("\r\n" + str);//创建新的内容=之前的内容+新输入的内容
            FileOutputStream out = new FileOutputStream("log.txt");  //输出流
            byte[] newb = wenzi.toString().getBytes();
            out.write(newb);
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    private boolean boolTTime() {
        //判断时间片
        if (tTime.getText().equals("")) {
            //时间片大小
            JOptionPane.showMessageDialog(null, "请输入时间片大小(数字)!", "提示", JOptionPane.INFORMATION_MESSAGE);
            return false;
        } else {
            try {
                //是否为数值
                parseDouble(tTime.getText());
            } catch (Exception ex) {
                JOptionPane.showMessageDialog(null, "时间片大小为数字!请重新输入!", "提示", JOptionPane.INFORMATION_MESSAGE);
                return false;
            }
        }
        return true;
    }


    public void startRun() {
        Runnable runnable = new Runnable() {
            public void run() {
                saveLog("------正在进行调度-------");
                lInfo.setText("------正在进行调度-------");
                while (allQue.size() > 0 && blinker != null) {
                    try {
                        runReady();//就绪队列
                        runIn(); //输入队列
                        runOut(); //输出队列
                        runWait(); //等待队列
                        showReady(readyQue);
                        saveLog("Programs in readyQue:\t" + tReady.getText()+"\r\n");
                        showIn(inQue);
                        saveLog("Programs in InQue:\t" + tInput.getText() + "\r\n");
                        for(PCB p:inQue)
                        {saveLog("(Programs in inQue):"+p.getpName()+"'s Current Instruction:"+
                                p.getpInstructions().get(p.getCurrentInstruction()).getIName()+"'s RemainTime:"+
                                p.getpInstructions().get(p.getCurrentInstruction()).getIRemainTime());}
                        showOut(outQue);
                        saveLog("Programs in OutQue:\t" + tOutput.getText() + "\r\n");
                        for(PCB p:outQue)
                        {saveLog("(Programs in outQue):"+p.getpName()+"'s Current Instruction:"+
                                p.getpInstructions().get(p.getCurrentInstruction()).getIName()+"'s RemainTime:"+
                                p.getpInstructions().get(p.getCurrentInstruction()).getIRemainTime());}
                        showWait(waitQue);
                        saveLog("Programs in WaitQue:\t" + tWait.getText() + "\r\n");

                        saveLog("_______________________________");
                        count++;
                        System.out.println(count);//控制台输出;
                        sleep(Long.parseLong(tTime.getText()));//休眠时间为:等待单位时间片的长度.休眠时间结束后继续进行CPU调度

                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                //初始化队列分配完毕
                if (allQue.size() == 0) {
                    bStart.setText("开始调度");
                    tCur.setText("");
                    lInfo.setText("调度已完成");
                    saveLog("调度已完成");
                } else {
                    lInfo.setText("调度已停止");
                    saveLog("调度已停止");
                }
            }
        };
        blinker = new Thread(runnable);
        blinker.start();
    }

    private void showAll(ArrayList<PCB> allQue) {
        tAll.setText("");
        for (PCB p : allQue) {
            tAll.setText(tAll.getText() +"\r\n" + p.getpName());
        }
    }

    private void showWait(ArrayList<PCB> waitQue) {
        tWait.setText("");
        for (PCB p : waitQue) {
            tWait.setText(tWait.getText() +"\r\n" + p.getpName());
        }
    }

    private void showOut(ArrayList<PCB> outQue) {
        tOutput.setText("");
        for (PCB p : outQue) {
            tOutput.setText(tOutput.getText() + "\r\n" + p.getpName());
        }
    }

    private void showIn(ArrayList<PCB> inQue) {
        tInput.setText("");
        for (PCB p : inQue) {
            tInput.setText(tInput.getText() + "\r\n" + p.getpName());
        }
    }

    private void showReady(ArrayList<PCB> readyQue) {
        tReady.setText("");
        for (PCB p : readyQue) {
            tReady.setText(tReady.getText() +"\r\n" + p.getpName());
        }
    }

    private void initQue() {
        //把就绪进程排成一个就绪队列,即readyQue
        //I，O，W三条指令实际上是不占有CPU的，执行这三条指令就应该将进程放入对应的等待队列（输入等待队列，输出等待队列 ，其他等待队列）。
        //先清空队列
        readyQue.clear();
        inQue.clear();
        outQue.clear();
        waitQue.clear();

        //分配排序队列
        for (PCB p : allQue
        ) {
            if (p.getpInstructions().get(0).getIName() == 'C') {
                readyQue.add(p);
            } else if (p.getpInstructions().get(0).getIName() == 'I') {
                inQue.add(p);
            } else if (p.getpInstructions().get(0).getIName() == 'O') {
                outQue.add(p);
            } else if (p.getpInstructions().get(0).getIName() == 'W') {
                waitQue.add(p);
            }
        }
    }

    private void runReady() {
        if (readyQue.size() > 0) {
            readyQue.get(0).getpInstructions().get(0).subIRemainTime();//调度首队列一次
            tCur.setText(readyQue.get(0).getpName());
            if (readyQue.get(0).getpInstructions().get(0).getIRemainTime() == 0) {
                //如果剩余时间为0,则说明该指令运行完成
                //把该指令移除,根据下一个指令判断队列
                readyQue.get(0).getpInstructions().remove(0);
                if (readyQue.get(0).getpInstructions().get(0).getIName() == 'C') {
                    readyQue.add(readyQue.get(0));//添加到ready末尾
                } else if (readyQue.get(0).getpInstructions().get(0).getIName() == 'I') {
                    inQue.add(readyQue.get(0));//添加到in末尾
                } else if (readyQue.get(0).getpInstructions().get(0).getIName() == 'O') {
                    outQue.add(readyQue.get(0));//添加到out末尾
                } else if (readyQue.get(0).getpInstructions().get(0).getIName() == 'W') {
                    waitQue.add(readyQue.get(0));//添加到wait末尾
                } else if (readyQue.get(0).getpInstructions().get(0).getIName() == 'H') {
                    //说明该进程完成
                    allQue.remove(readyQue.get(0));
                }
                readyQue.remove(readyQue.get(0));
            } else {
                readyQue.add(readyQue.get(0));//移动到末尾
                readyQue.remove(readyQue.get(0));
            }
        }
    }

    private void runIn() {
        if (inQue.size() > 0) {
            for(PCB p: inQue)
                for(int i=0;i<inQue.size();i++)
                    //inQue.get(0)
                    p.getpInstructions().get(i).subIRemainTime();//调度首队列一次
            if (inQue.get(0).getpInstructions().get(0).getIRemainTime() == 0) {
                //如果剩余时间为0,则说明运行完成
                //把该指令移除,根据下一个指令判断队列
                inQue.get(0).getpInstructions().remove(0);
                if (inQue.get(0).getpInstructions().get(0).getIName() == 'C') {  //C表示在CPU上计算
                    readyQue.add(inQue.get(0));//添加到ready末尾
                } else if (inQue.get(0).getpInstructions().get(0).getIName() == 'I') { //I表示输入
                    inQue.add(inQue.get(0));//添加到in末尾
                } else if (inQue.get(0).getpInstructions().get(0).getIName() == 'O') { //O表示输出
                    outQue.add(inQue.get(0));//添加到out末尾
                } else if (inQue.get(0).getpInstructions().get(0).getIName() == 'W') { //W表示进程等待
                    waitQue.add(inQue.get(0));//添加到wait末尾
                } else if (inQue.get(0).getpInstructions().get(0).getIName() == 'H') { //H表示进程结束
                    //说明该进程完成
                    allQue.remove(inQue.get(0));
                }
                inQue.remove(inQue.get(0));
            } else {
                //inQue.add(inQue.get(0));//移动到末尾
                //inQue.remove(inQue.get(0));
            }
        }
    }

    private void runOut() {
        if (outQue.size() > 0) {
            outQue.get(0).getpInstructions().get(0).subIRemainTime();//调度首队列一次
            if (outQue.get(0).getpInstructions().get(0).getIRemainTime() == 0) {
                //如果剩余时间为0,则说明运行完成
                //把该指令移除,根据下一个指令判断队列
                outQue.get(0).getpInstructions().remove(0);
                if (outQue.get(0).getpInstructions().get(0).getIName() == 'C') {
                    readyQue.add(outQue.get(0));//添加到ready末尾
                } else if (outQue.get(0).getpInstructions().get(0).getIName() == 'I') {
                    inQue.add(outQue.get(0));//添加到in末尾
                } else if (outQue.get(0).getpInstructions().get(0).getIName() == 'O') {
                    outQue.add(outQue.get(0));//添加到out末尾
                } else if (outQue.get(0).getpInstructions().get(0).getIName() == 'W') {
                    waitQue.add(outQue.get(0));//添加到wait末尾
                } else if (outQue.get(0).getpInstructions().get(0).getIName() == 'H') {
                    //说明该进程完成
                    if (allQue.size() > 0) {
                        allQue.remove(outQue.get(0));
                    }
                }
                outQue.remove(outQue.get(0));
            } else {
                outQue.add(outQue.get(0));//移动到末尾
                outQue.remove(outQue.get(0));
            }
        }
    }

    private void runWait() {
        if (waitQue.size() > 0) {
            waitQue.get(0).getpInstructions().get(0).subIRemainTime();//调度首队列一次
            if (waitQue.get(0).getpInstructions().get(0).getIRemainTime() == 0) {
                //如果剩余时间为0,则说明运行完成
                //把该指令移除,根据下一个指令判断队列
                waitQue.get(0).getpInstructions().remove(0);
                if (waitQue.get(0).getpInstructions().get(0).getIName() == 'C') {
                    readyQue.add(waitQue.get(0));//添加到ready末尾
                } else if (waitQue.get(0).getpInstructions().get(0).getIName() == 'I') {
                    inQue.add(waitQue.get(0));//添加到in末尾
                } else if (waitQue.get(0).getpInstructions().get(0).getIName() == 'O') {
                    outQue.add(waitQue.get(0));//添加到out末尾
                } else if (waitQue.get(0).getpInstructions().get(0).getIName() == 'W') {
                    waitQue.add(waitQue.get(0));//添加到wait末尾
                } else if (waitQue.get(0).getpInstructions().get(0).getIName() == 'H') {
                    //说明该进程完成
                    allQue.remove(waitQue.get(0));
                }
                waitQue.remove(waitQue.get(0));
            } else {
                waitQue.add(waitQue.get(0));//移动到末尾
                waitQue.remove(waitQue.get(0));
            }
        }
    }

    private void readFile() {
        //读取文件
        if (file != null) {
            try {
                BufferedReader in = new BufferedReader(new FileReader(file));
                String str;
                allQue.clear();
                PCB pcb = null;
                while ((str = in.readLine()) != null) {
                    if (str.charAt(0) == 'P') {
                        //创建新的进程
                        pcb = new PCB();
                        pcb.setpName(str);
                    } else {
                        //创建新的指令集
                        Instructions instructions = new Instructions();
                        instructions.setIName(str.charAt(0));
                        instructions.setIRuntime(parseDouble(str.substring(1)));
                        instructions.setIRemainTime(instructions.getIRuntime());//刚开始剩余时间与运行时间一致
                        assert pcb != null;
                        pcb.getpInstructions().add(instructions);
                        if (instructions.getIName() == 'H') {
                            //H代表当前进程结束,添加到就绪队列
                            allQue.add(pcb);
                        }

                    }
                }
            } catch (IOException e) {
                System.out.println("文件读取错误!");
            }
        }
    }

    private void chooseFile() {
        //选择文件
        FileNameExtensionFilter filter = new FileNameExtensionFilter("*.txt", "txt");
        JFileChooser jfc = new JFileChooser(".");//当前目录下
        jfc.setFileFilter(filter);
        jfc.setMultiSelectionEnabled(false);//不允许多选
        jfc.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
        int result = jfc.showSaveDialog(null);
        if (result == JFileChooser.APPROVE_OPTION) {
            //JFileChooser.APPROVE_OPTION是个整型常量，代表0。
            // 就是说当返回0的值我们才执行相关操作，否则什么也不做。
            file = jfc.getSelectedFile();
        }

    }

    private void init() {
        //界面初始化
        JFrame jFrame = new JFrame();
        jFrame.setTitle("时间片轮转调度");
        Container con = jFrame.getContentPane();
        con.setLayout(null);
        bFIle = new JButton("打开文件");
        bFIle.setBounds(50, 50, 150, 30);

        bStart = new JButton("开始调度");
        bStart.setBounds(220, 50, 150, 30);

        bStop = new JButton("暂停调度");
        bStop.setBounds(390, 50, 150, 30);

        JLabel ltime = new JLabel("设置时间片大小:");
        ltime.setBounds(560, 50, 80, 30);
        tTime = new JTextField();
        tTime.setBounds(650, 50, 150, 30);
        tTime.setText("500");

        JLabel lCur = new JLabel("当前运行进程:");
        lCur.setBounds(50, 100, 150, 30);
        tCur = new JTextField();
        tCur.setBounds(50, 130, 150, 30);

        lInfo = new JLabel("");//提示信息
        lInfo.setBounds(350, 130, 300, 30);
        lInfo.setForeground(Color.red);


        JLabel lall = new JLabel("初始队列:");
        lall.setBounds(50, 200, 150, 30);
        tAll = new JTextArea(6, 4);
        tAll.setBounds(50, 230, 150, 250);

        JLabel lr = new JLabel("就绪队列:");
        lr.setBounds(220, 200, 150, 30);
        tReady = new JTextArea(6, 4);
        tReady.setBounds(220, 230, 150, 250);

        JLabel lin = new JLabel("输入队列:");
        lin.setBounds(390, 200, 150, 30);
        tInput = new JTextArea(6, 4);
        tInput.setBounds(390, 230, 150, 250);

        JLabel lout = new JLabel("输出队列:");
        lout.setBounds(560, 200, 150, 30);
        tOutput = new JTextArea(6, 4);
        tOutput.setBounds(560, 230, 150, 250);

        JLabel lw = new JLabel("等待队列:");
        lw.setBounds(730, 200, 150, 30);
        tWait = new JTextArea(6, 4);
        tWait.setBounds(730, 230, 150, 250);

        con.add(bFIle);
        con.add(bStart);
        con.add(bStop);
        con.add(ltime);
        con.add(tTime);
        con.add(lCur);
        con.add(tCur);
        con.add(lInfo);
        con.add(lall);
        con.add(tAll);
        con.add(lr);
        con.add(tReady);
        con.add(lin);
        con.add(tInput);
        con.add(lout);
        con.add(tOutput);
        con.add(lw);
        con.add(tWait);
        jFrame.setBounds(200, 200, 1000, 600);  //设置窗口的属性 窗口位置以及窗口的大小
        jFrame.setVisible(true);
        jFrame.setDefaultCloseOperation(DISPOSE_ON_CLOSE);

    }


    public static void main(String[] args) {

        MainFrame mainFrame = new MainFrame();
    }

}
