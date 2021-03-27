import java.util.Random;

import static java.lang.Integer.parseInt;

public class Threaded extends Thread {

    static double x;
    static double y;
    static double circulo = 0;
    static double quadrado = 0;
    static int size;
    static Random random = new Random();

    public static void main(String[] args) {
        size = parseInt(args[0]);
        Thread thread = new Thread();
        thread.start();

        double startTime = System.nanoTime();
        while (quadrado <= size){
            x = random.nextDouble();
            y = random.nextDouble();

            if(x*x + y*y <= 1) {
                circulo++;
            }
            quadrado++;
        }

        double pi = (circulo/quadrado)*4;
        System.out.println(pi);


        double endTime = System.nanoTime();
        double totalTime = (endTime - startTime) / 1000000000;
        System.out.println(totalTime+ " seconds");
    }

    public void run() {
        while (quadrado <= size){
            x = random.nextDouble();
            y = random.nextDouble();

            if(x*x + y*y <= 1) {
                circulo++;
            }
            quadrado++;
        }
    }
}
