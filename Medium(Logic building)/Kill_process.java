public class Solution {

    public List < Integer > killProcess(List < Integer > pid, List < Integer > ppid, int kill) {
        List < Integer > l = new ArrayList < > ();
        if (kill == 0)
            return l;
        l.add(kill);
        for (int i = 0; i < ppid.size(); i++)
            if (ppid.get(i) == kill)
                l.addAll(killProcess(pid, ppid, pid.get(i)));
        return l;
    }
}

/*Algorithm

Since killing a process leads to killing all its children processes, the simplest solution is to traverse over the array and find out all the children of the process to be killed. Further, for every child chosen to be killed we recursively make call to the killProcess function now treating this child as the new parent to be killed. In every such call, we again traverse over the array now considering the id of the child process, and continue in the same fashion. Further, at every step, for every process chosen to be killed, it is added to the list that needs to be returned at the end.

Complexity Analysis

    Time complexity : . function calls will be made in the worst case

    Space complexity : . The depth of the recursion tree can go upto .*/
