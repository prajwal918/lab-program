package pack;

import converter.*;

public class ConverterDriver {
    
    public static void main(String[] args) {
        try {
        // TODO Auto-generated method stub
        DistanceConverter distobj = new DistanceConverter();
        distobj.Convert();
        
        TimeConverter timeobj = new TimeConverter();
        timeobj.convert();
        } catch (Exception e) {
            System.err.println("Error occurred: " + e.getMessage());
            e.printStackTrace();
        }
        }
}