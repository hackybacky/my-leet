class Solution {

    public boolean exist(char[][] board, String word) {

        

        //boolean matrix to keep track of visited letters

        boolean[][] isV = new boolean[board.length][board[0].length];

        

        //assume word not found

        boolean flag = false;

        

        //loop to search the first letter of the word

        for(int i=0; i<board.length; i++)

        {

            for(int j=0; j<board[0].length; j++)

            {

                if(board[i][j] == word.charAt(0)) 

                {

                    //if first letter found mark it as visited

                    isV[i][j] = true;

                    

                    //search for the rest of the letters in word

                    flag = search(board, word, isV, 1, i, j);

                    
                    isV[i][j]=false;
                    //if this search returs true we found the word

                    if(flag) break;

                }

            }

            

            //breaking loop if word found

            if(flag) break;

        }

        

        //returning answer

        return flag;

    }

    

    public static boolean search(char[][] board, String word, boolean[][] isV, int sz, int i, int j)

    {

        

        if(sz == word.length()) return true;

        

        boolean r = false, d = false, l = false, u = false;

        

        //go right

        //check if the right move is a valid move or not

        if(j+1<board[i].length && !isV[i][j+1] && board[i][j+1] == word.charAt(sz))

        {

            isV[i][j+1] = true;

            

            r = search(board, word, isV, sz+1, i, j+1);

            

            isV[i][j+1] = false;

            

            if(r) return r;

        }

        

        //go down

        //check if down move is a valid move or not

        if(i+1<board.length && !isV[i+1][j] && board[i+1][j] == word.charAt(sz))

        {

            isV[i+1][j] = true;

            

            d = search(board, word, isV, sz+1, i+1, j);

            

            isV[i+1][j] = false;

            

            if(d) return d;

        }

        

        //go left

        //check is left move is a valid move or not

        if(j-1>-1 && !isV[i][j-1] && board[i][j-1] == word.charAt(sz))

        {

            isV[i][j-1] = true;

            

            l = search(board, word, isV, sz+1, i, j-1);

            

            isV[i][j-1] = false;

            

            if(l) return l;

        }

        

        //go up

        //check if up move is a valid move or not

        if(i-1>-1 && !isV[i-1][j] && board[i-1][j] == word.charAt(sz))

        {

            isV[i-1][j] = true;

            

            u = search(board, word, isV, sz+1, i-1, j);

            

            isV[i-1][j] = false;

            

            if(u) return u;

        }

        

        // if any path returns true

        return r || l || d || u;

    }

}