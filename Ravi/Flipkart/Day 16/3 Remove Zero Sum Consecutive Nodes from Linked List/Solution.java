/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        
        ListNode p = head;
        int n = 0;
        
        while(p != null) {
            n++;
            p = p.next;    
        }
        
        int[] arr = new int[n];
        p = head;
        
        int ii = 0;
        while(p != null) {
            arr[ii] = p.val;
            p = p.next;
            ii++;
        }
        
        int[] psum = new int[n];
        psum[0] = arr[0];
        
        for(int i = 1; i < n; i++) psum[i] += arr[i] + psum[i - 1];
        
        HashMap<Integer, Integer> hm = new HashMap<>();
        
        for(int i = 0; i < n; i++) hm.put(psum[i], i);
        
        ListNode ans = null;
        
        ListNode pp = ans;
        
        for(int i = 0; i < n; i++) {
            
            if(psum[i] == 0) {
                ans = null;
                continue;
            }
            
            if(hm.get(psum[i]) == i) {
                if(ans == null) {
                    ans = new ListNode(arr[i]);
                    pp = ans;
                }
                else {
                    pp.next = new ListNode(arr[i]);
                    pp = pp.next;
                }
            } else {
                if(ans == null) {
                    ans = new ListNode(arr[i]);
                    pp = ans;
                }
                else {
                    pp.next = new ListNode(arr[i]);
                    pp = pp.next;
                }
                i = hm.get(psum[i]);
            }
        }
        
        return ans;
        
    }
}
