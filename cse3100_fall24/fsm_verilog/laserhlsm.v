module LaserDistMeasurer_HLSM(clk, rst, b, s, l, D);
   input clk, rst;
   input b, s;
   output reg l;
   output reg [15:0] D;
   
   localparam [3:0] S0 = 0,
                    S1 = 1,
                    S2 = 2,
                    S3 = 3,
                    S4 = 4;

   reg [3:0] State;        // HLSM State
   reg [15:0] Dctr;        // HLSM Variable
 
   always @(posedge clk) begin
      if (rst) begin 
         // Initial state
         State = S0;
      end
      else begin
         // State transitions
         case (State) 
            S0: begin
               State = S1;
            end
            S1: begin
               if (b) begin
                  State = S2;
               end
               else if (!b) begin
                  State = S1;
               end
            end
            S2: begin
               State = S3;   
            end
            S3: begin
               if (s) begin
                  State = S4;
               end
               else if (!s) begin
                  State = S3;
               end
            end
            S4: begin
               State = S1;
            end
            default: begin
               State = S0;
            end
         endcase
      end

      // State actions
      case (State) 
         S0: begin
            l = 0;
            D = 0;
            Dctr = 0;
         end        
         S1: begin
            l = 0;
         end
         S2: begin
            l = 1;        
         end
         S3: begin
            l = 0;      
            Dctr = Dctr + 1; 
         end
         S4: begin
            D = Dctr >> 1;
         end    
         default: begin
            l = 0;            
            D = 0; 
            Dctr = 0;
         end
      endcase
   end
endmodule