/**
利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。
若压缩后的字符串没有变短，则返回原先的字符串。
给定一个string iniString为待压缩的串(长度小于等于10000)，保证串内字符均由大小写英文字母组成，返回一个string，为
所求的压缩后或未变化的串。
 */

 import java.util.*;

public class Zipper {
    public String zipString(String iniString) {
        // write code here
        if (iniString.length() == 0)
            return iniString;
        StringBuilder sb = new StringBuilder();
        char cur = iniString.charAt(0);
        int cnt = 1;
        for (int i = 1; i < iniString.length(); i++) {
            if (iniString.charAt(i) == cur) {
                cnt++;
            } else {
                sb.append(cur); sb.append(cnt);
                cnt = 1; cur = iniString.charAt(i);
            }
        }
        sb.append(cur); sb.append(cnt);
        return sb.length() < iniString.length() ? sb.toString() : iniString;
    }
}