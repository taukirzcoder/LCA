/*Let us begin by storing the dictionary first in the constructor. To determine if a word's abbreviation is unique with respect to a word in the dictionary, we check if all the following conditions are met:

    They are not the same word.
    They both have equal lengths.
    They both share the same first and last letter.

Note that Condition #1 is implicit because from the problem statement:

    A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.*/

public class ValidWordAbbr {
    private final String[] dict;

    public ValidWordAbbr(String[] dictionary) {
        dict = dictionary;
    }

    public boolean isUnique(String word) {
        int n = word.length();
        for (String s : dict) {
            if (word.equals(s)) {
                continue;
            }
            int m = s.length();
            if (m == n
                && s.charAt(0) == word.charAt(0)
                && s.charAt(m - 1) == word.charAt(n - 1)) {
                return false;
            }
        }
        return true;
    }
}

/*Complexity analysis

    Time complexity : for each isUnique call. Assume that is the number of words in the dictionary, each isUnique call takes time.*/
