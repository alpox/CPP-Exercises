/**
 * Created by Elias on 01.11.16.
 */
public class StringMatcher implements Matcher<String> {

    @Override
    public boolean match(String elem) {
        return elem.endsWith("foo");
    }
}
