import java.util.Random;
import java.util.Vector;

/**
 * Created by Elias on 01.11.16.
 */

public class Benchmark {
    public static void main(String[] args) {
        StringMatcher matcher = new StringMatcher();
        Vector<String> vec = new Vector<>();

        Random rnd = new Random();

        for(int i = 0; i < 5500000; i++) {
            String str = "";
            for(int p = 0; p < 10; p++) {
                char c = (char)(rnd.nextInt(24) + 65);
                str += c;
            }
            if(rnd.nextInt(1500000) == 0) str += "foo";
            vec.add(str);
        }

        long startTime = System.currentTimeMillis();
        String found = Finder.findIf(vec.iterator(), matcher);
        long endTime = System.currentTimeMillis();

        System.out.println("Total execution time: " + (endTime-startTime) + "ms");
        System.out.println("Found value: " + found);
    }
}
