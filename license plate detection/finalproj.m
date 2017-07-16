clear all
clc

%disp(sprintf('enter the file location::'));
prompt='enter the file location::\n';
str = input(prompt,'s');
I=imread(str);
%retrieves the image directory
s=size(I);
%figure(1)
%imshow(I)
I=rgb2gray(I);
%figure(2)
%imshow(I);
I=medfilt2(I);
%figure(3)
%imshow(I)
l=graythresh(I);
%figure(4)
%imshow(I)
I=im2bw(I,l);
%figure(5)
%imshow(I)
%%imshow(B);
I=imcomplement(I);
%figure(6)
%imshow(I);
SE = strel('square',3);
D=imdilate(I,SE);
%figure(7)
%imshow(D);
n=1;
%r=zeros(2000,1);
for i = 1:s(1)
    h=0;count=0;
    for j = 1:s(2)
        r(n,j)=D(i,j);
        if D(i,j) == 0
            h=1;
            count=count+1;
            %disp(sprintf('%d,%d == %d',i,j,I(i,j)));
        else 
            continue;
        end
    end
    if h==1 && count~=s(2)
        n=n+1;
    end
end
sr=size(r);
sr;
%figure(8)
%imshow(r)
r=imcomplement(r);
%{
%figure(5)
hold on
%imshow(r)
Iprops=regionprops(final,'BoundingBox','Image');
for n=1:size(Iprops,1)
    rectangle('Position',Iprops(n).BoundingBox,'EdgeColor','g')
end
hold off
%}
bw=bwareafilt(r,[(sr(1)*sr(2)/16) (sr(1)*sr(2)/4)]);
%figure(9)
%imshow(bw)
r=bw;
r=imcomplement(r);
n=1;
for i = 1:sr(1)
    h=0;
    for j = 1:sr(2)
        rr(n,j)=r(i,j);
        if r(i,j) == 0
            h=1;
            %disp(sprintf('%d,%d == %d',i,j,I(i,j)));
        else 
            continue;
        end
    end
    if h==1
        n=n+1;
    end
end
sr=size(rr);
sr;
n=1;
for i = 1:sr(2)
    h=0;
    for j = 1:sr(1)
        rrr(j,n)=rr(j,i);
        if rr(j,i) == 0
            h=1;
            %disp(sprintf('%d,%d == %d',i,j,I(i,j)));
        else 
            continue;
        end
    end
     if h==1 
        n=n+1;
    end
end
%figure(10)
%imshow(rrr)
sr=size(rrr);
%trrr=rrr;
%figure(11)
%imshow(rrr)
bw=bwareafilt(rrr,[(sr(1)*sr(2)*0.007) (sr(1)*sr(2)*0.25)]);
rrr=bw;
t=ocr(rrr);
ochr=t.Text;
%figure(12)
%imshow(rrr)
labeledImage = bwlabel(rrr);
measurements = regionprops(labeledImage, 'BoundingBox', 'Image');
for k = 1 : length(measurements)
  thisBB = measurements(k).BoundingBox;
  rectangle('Position', [thisBB(1),thisBB(2),thisBB(3),thisBB(4)],...
  'EdgeColor','g','LineWidth',2 );
end
L=labeledImage;
%nnn=max(L(:)); % number of objects
%ObjCell=cell(nnn,1);
bb=measurements;
siz=sr;
Iprops1=regionprops(rrr,'BoundingBox','Image');
NR3=cat(1,Iprops1.BoundingBox);
ObjCell={Iprops1.Image};
close all
%{
for i=1:nnn
      % Get the bb of the i-th object and offest by 2 pixels in all
      % directions
      bb_i=ceil(bb(i).BoundingBox);
      idx_x=[bb_i(1)-2 bb_i(1)+bb_i(3)+2];
      idx_y=[bb_i(2)-2 bb_i(2)+bb_i(4)+2];
      if idx_x(1)<1, idx_x(1)=1; end
      if idx_y(1)<1, idx_y(1)=1; end
      if idx_x(2)>siz(2), idx_x(2)=siz(2); end
      if idx_y(2)>siz(1), idx_y(2)=siz(1); end
      % Crop the object and write to ObjCell
      im=L==i;
      ObjCell{i}=im(idx_y(1):idx_y(2),idx_x(1):idx_x(2));
end
%}
% Visualize the individual objects
isr=size(ObjCell);
%{
for i=1:isr(2)
    %figure(i+7)
    %ObjCell{i}=imresize(ObjCell{i},[42 24]);
    %ObjCell{1,i}=imcomplement(ObjCell{1,i});
    %imshow(ObjCell{1,i})
    o=ocr(ObjCell{1,i});
    o.Text
end
%}
for i=1:42
    for j=1:24
        pen(i,j)=0;
    end
end
carnum=[];
for i=1:isr(2)
    present=10000;
    image1=imresize(ObjCell{1,i},[42 24]);
    A=imread('A.bmp');
    [testb1,testb2]=find(image1-A~=0);
    testsiz=size(testb1);
    if testsiz(1)<present
        present=testsiz(1);
        letter='A';
    end
	B=imread('B.bmp');
	[testb1,testb2]=find(image1-B~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='B';
	end
    C=imread('C.bmp');
	[testb1,testb2]=find(image1-C~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='C';
	end
    D=imread('D.bmp');
	[testb1,testb2]=find(image1-D~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='D';
	end
    E=imread('E.bmp');
	[testb1,testb2]=find(image1-E~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='E';
	end
    F=imread('F.bmp');
	[testb1,testb2]=find(image1-F~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='F';
	end
    G=imread('G.bmp');
	[testb1,testb2]=find(image1-G~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='G';
	end
    H=imread('H.bmp');
	[testb1,testb2]=find(image1-H~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='H';
	end
    I=imread('I.bmp');
	[testb1,testb2]=find(image1-I~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='I';
	end
    J=imread('J.bmp');
	[testb1,testb2]=find(image1-J~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='J';
	end
    K=imread('K.bmp');
	[testb1,testb2]=find(image1-A~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='A';
	end
    L=imread('L.bmp');
	[testb1,testb2]=find(image1-L~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='L';
	end
    M=imread('M.bmp');
	[testb1,testb2]=find(image1-M~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='M';
	end
    N=imread('N.bmp');
	[testb1,testb2]=find(image1-N~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='N';
	end
    O=imread('O.bmp');
	[testb1,testb2]=find(image1-O~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='O';
	end
    P=imread('P.bmp');
	[testb1,testb2]=find(image1-P~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='P';
	end
    Q=imread('Q.bmp');
	[testb1,testb2]=find(image1-Q~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='Q';
	end
    R=imread('R.bmp');
	[testb1,testb2]=find(image1-R~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='R';
	end
    S=imread('S.bmp');
	[testb1,testb2]=find(image1-S~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='S';
	end
    T=imread('T.bmp');
	[testb1,testb2]=find(image1-T~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='T';
	end
    U=imread('U.bmp');
	[testb1,testb2]=find(image1-U~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='U';
	end
    V=imread('V.bmp');
	[testb1,testb2]=find(image1-V~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='V';
	end
    W=imread('W.bmp');
	[testb1,testb2]=find(image1-W~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='W';
	end
    X=imread('X.bmp');
	[testb1,testb2]=find(image1-X~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='X';
	end
    Y=imread('Y.bmp');
	[testb1,testb2]=find(image1-Y~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='Y';
	end
    Z=imread('Z.bmp');
	[testb1,testb2]=find(image1-Z~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='Z';
	end
    Afill=imread('fillA.bmp');
	[testb1,testb2]=find(image1-Afill~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='A';
	end
    Bfill=imread('fillB.bmp');
	[testb1,testb2]=find(image1-Bfill~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='B';
	end
    Dfill=imread('fillD.bmp');
	[testb1,testb2]=find(image1-Dfill~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='D';
	end
    Ofill=imread('fillO.bmp');
	[testb1,testb2]=find(image1-Ofill~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='O';
	end
    Pfill=imread('fillP.bmp');
	[testb1,testb2]=find(image1-Pfill~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='P';
	end
    Qfill=imread('fillQ.bmp');
	[testb1,testb2]=find(image1-Qfill~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='Q';
	end
    Rfill=imread('fillR.bmp');
	[testb1,testb2]=find(image1-Rfill~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='R';
	end
    
    %Number
    one=imread('1.bmp');
	[testb1,testb2]=find(image1-one~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='1';
	end  
    two=imread('2.bmp');
	[testb1,testb2]=find(image1-two~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='2';
	end
    three=imread('3.bmp');
	[testb1,testb2]=find(image1-three~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='3';
	end
    four=imread('4.bmp');
	[testb1,testb2]=find(image1-four~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='4';
	end
    five=imread('5.bmp');
	[testb1,testb2]=find(image1-five~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='5';
	end
    six=imread('6.bmp');
	[testb1,testb2]=find(image1-six~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='6';
	end
    seven=imread('7.bmp');
	[testb1,testb2]=find(image1-seven~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='7';
	end
    eight=imread('8.bmp');
	[testb1,testb2]=find(image1-eight~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='8';
	end
    nine=imread('9.bmp');
	[testb1,testb2]=find(image1-nine~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='9';
	end
    zero=imread('0.bmp');
	[testb1,testb2]=find(image1-zero~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='0';
	end
    zerofill=imread('fill0.bmp');
	[testb1,testb2]=find(image1-zerofill~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='0';
	end
    fourfill=imread('fill4.bmp');
	[testb1,testb2]=find(image1-fourfill~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='4';
	end
    sixfill=imread('fill6.bmp');
	[testb1,testb2]=find(image1-sixfill~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='6';
	end
    sixfill2=imread('fill6_2.bmp');
	[testb1,testb2]=find(image1-sixfill2~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='6';
	end
    eightfill=imread('fill8.bmp');
	[testb1,testb2]=find(image1-eightfill~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='8';
	end
    ninefill=imread('fill9.bmp');
	[testb1,testb2]=find(image1-ninefill~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='9';
	end
    ninefill2=imread('fill9_2.bmp');
	[testb1,testb2]=find(image1-ninefill2~=0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='9';
    end
	[testb1,testb2]=find(image1-pen~= 0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='-';
    end
    pen=imcomplement(pen);
	[testb1,testb2]=find(image1-pen~= 0);
	testsiz=size(testb1);
	if testsiz(1)<present
		present=testsiz(1);
		letter='-';
    end
    %disp(sprintf('%d %d\n',i,present));
    carnum=[carnum letter];
end
carnum
fid1 = fopen('carnum.txt', 'wt');
fprintf(fid1,'%s\n',carnum);
fprintf(fid1,'%s',ochr);
fclose(fid1);
winopen('carnum.txt')
