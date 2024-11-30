// ButtonPress_FSM
module BP_FSM(clk, rst, b, y);
   input clk, rst;    
   input b;
   output reg y;
  
   localparam [1:0] BP_Init = 0,
                    BP_Out1 = 1,
                    BP_Out2 = 2;
   
   reg [1:0] BP_State;
   
   always @(posedge clk) begin
      if (rst) begin
         // Initial state
         BP_State = BP_Init;
      end
      else begin
         // State transitions
         case (BP_State) 
            BP_Init: begin
               if (!b) begin
                  BP_State = BP_Init;
               end
               else if (b) begin
                  BP_State = BP_Out1;
               end
            end
            
            BP_Out1: begin
               BP_State = BP_Out2;
            end
            
            BP_Out2: begin
               BP_State = BP_Init;
            end
            
            default: begin
               BP_State = BP_Init;
            end
         endcase
      end
      
      // State actions
      case (BP_State) 
         BP_Init: begin
            y = 0;
         end
            
         BP_Out1: begin
            y = 1;
         end
            
         BP_Out2: begin
            y = 0;
         end
         
         default: begin
            y = 0;
         end
      endcase
   end
endmodule