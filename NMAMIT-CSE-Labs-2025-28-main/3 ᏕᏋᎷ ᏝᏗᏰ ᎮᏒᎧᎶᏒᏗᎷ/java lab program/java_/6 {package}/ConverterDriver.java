package pack;

import converter.*;

public class ConverterDriver {
    
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        DistanceConverter distobj = new DistanceConverter();
        distobj.Convert();
        
        TimeConverter timeobj = new TimeConverter();
        timeobj.convert();
    }
}