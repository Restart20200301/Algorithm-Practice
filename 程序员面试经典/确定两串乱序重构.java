/**
给定两个字符串，请编写程序，确定其中一个字符串的字符重新排列后，
能否变成另一个字符串。这里规定大小写为不同字符，且考虑字符串中的
空格。
给定一个string stringA和一个string stringB，请返回一个bool，
代表两串是否重新排列后可相同。保证两串的长度都小于等于5000。
 */

 import java.util.*;

public class Same {
    public boolean checkSam(String stringA, String stringB) {
        // write code here
        if (stringA.length() != stringB.length())
            return false;
        return sort(stringA).equals(sort(stringB));
    }

    private String sort(String str) {
        char[] arr = str.toCharArray();
        Arrays.sort(arr);
        return new String(arr);
    }
}