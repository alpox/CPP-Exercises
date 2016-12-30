import java.util.Iterator;

/**
 * Created by Elias on 01.11.16.
 */
public class Finder {
    public static <T> T findIf(Iterator iter, Matcher matcher) {
        while(iter.hasNext()) {
            T element = (T)iter.next();
            if(matcher.match(element)) return element;
        }
        return null;
    }
}
