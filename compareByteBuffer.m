function [differenceTBL] = compareByteBuffer(A,B)
% function [differenceTBL] = compareByteBuffer(A,B)

    % Check the conversion
    ind = min(numel(B),numel(A));
    clear TBL;
        TBL.Index    = (1:ind)';
        TBL.A        = A(1:ind)';
        TBL.B        = B(1:ind)';
        TBL.check    = A(1:ind)' == B(1:ind)';
        TBL = struct2table(TBL);

    differenceTBL = TBL(TBL.check==false,:);
    disp(differenceTBL);
    disp("A["+numel(A)+'] <==> B['+numel(B)+"]")
    

end