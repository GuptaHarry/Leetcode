class Solution {
    public double largestTriangleArea(int[][] points) {
        double max = 0;

        for(int i = 0; i<points.length; i++){
            for(int j=i+1; j<points.length; j++){
                for(int k = j+1; k<points.length; k++){
                    // Shoelace theorem 3D view
                    //(1/2) |x1(y2 â y3) + x2(y3 â y1) + x3(y1 â y2)|
                    double area = 0.5 * Math.abs
                    (points[i][0] *(points[j][1] - points[k][1]) + 
                    points[j][0] *(points[k][1] - points[i][1]) + 
                    points[k][0] *(points[i][1] - points[j][1]));
                    
                    max = Math.max(max,area);
                }
            }
        }
        return max;
    }
}