/**
 请编写一个方法，将字符串中的空格全部替换为“%20”。假定该字符串有足够的空间存放新增的字符，
 并且知道字符串的真实长度(小于等于1000)，同时保证字符串由大小写的英文字母组成。
 给定一个string iniString 为原始的串，以及串的长度 int len, 返回替换后的string。
 */

 import java.util.*;

public class Replacement {
    public String replaceSpace(String iniString, int length) {
        // write code here
        int cnt = 0;
        for (int i = 0; i < length; i++) {
            if (iniString.charAt(i) == ' ')
                cnt++;
        }
        StringBuilder sb = new StringBuilder(length + cnt * 2);
        for (int j = 0; j < length; j++) {
            if (iniString.charAt(j) == ' ') {
                sb.append("%20");
            } else {
                sb.append(iniString.charAt(j));
            }
        }
        return sb.toString();
    }
}