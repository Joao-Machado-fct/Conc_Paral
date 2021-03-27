import java.util.Random;

import static java.lang.Integer.parseInt;

public class Sequencial {

    public static void main(String[] args) {
        Random random = new Random();
        double x;
        double y;
        double circulo = 0;
        double quadrado = 0;

        double startTime = System.nanoTime();
        for(int k = 0; k < parseInt(args[0]); k++) {
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
}
