class inter_woven_strings
{
    public static boolean is_inter_woven(String str1, String str2, String str3,int i, int j, int k)
    {
        if(i == str1.length() && j == str2.length() && k == str3.length()){
            return true;
        }
        
        if(k == str3.length()){
            return false;
        }
        
        if (i < str1.length() && str1.charAt(i) == str3.charAt(k) && is_inter_woven(str1, str2, str3, i+1, j, k+1))
            return true;

        if (j < str2.length() && str2.charAt(j) == str3.charAt(k) && is_inter_woven(str1, str2, str3, i, j+1, k+1))
            return true;
        
        return false;
    }

    public static void main(String args[])
    {
        String a = "aaa";
        String b = "aaaf";
        String c = "aaafaaa";
        boolean result = is_inter_woven(a, b, c, 0, 0, 0);

        System.out.println(result);
    }
}


