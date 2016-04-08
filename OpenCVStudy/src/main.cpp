/*
 * main.cpp
 * OpenCV study, based on an article from Programista 00/2012
 *  Created on: 14-01-2015
 *      Author: mateusz
 */


#include <stdio.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>

void justShowVideo()
{
	// pobranie obrazu z dowolnej kamery
		CvCapture* obraz = cvCaptureFromCAM(CV_CAP_ANY);
		if (!obraz)
		{
			fprintf(stderr, "Brak kamery\n");
			return ;
		}
	// przygotowanie okienka
		cvNamedWindow("okienko", CV_WINDOW_AUTOSIZE);

	// pobieranie kolejnych klatek a¿ do naciœniêcia klawisza ESC
		while (1)
		{
			IplImage * klatka = cvQueryFrame(obraz);
			if (!klatka)
			{
				fprintf(stderr, "Brak klatki\n");
				break;
			}
	// wyœwietlanie klatek w okienku
			cvShowImage("okienko", klatka);
			if ((cvWaitKey(10) & 255) == 27)
				break;
		}
	// porz¹dkowanie
		cvReleaseCapture (&obraz);
		cvDestroyWindow("okienko");
}

void showCircles()
{

	CvCapture* obraz = cvCaptureFromCAM (CV_CAP_ANY);
	  if ( !obraz ) {
	  fprintf( stderr, "Brak kamery\n" );
	  return ;
	  }
	  cvNamedWindow( "okienko", CV_WINDOW_AUTOSIZE );
	  CvSize parzysty;
	  while ( 1 ) {
	   IplImage* klatka = cvQueryFrame( obraz );
	   if ( !klatka ) {
	    fprintf( stderr, "Brak klatki\n" );
	    break;
	    }
	   parzysty = cvSize( klatka->width & -2,
	klatka->height & -2 );
	   IplImage* szary = cvCreateImage(
	parzysty, IPL_DEPTH_8U, 1 );
	   IplImage* maly = cvCreateImage(
	cvSize(parzysty.width/2, parzysty.height/2),
	IPL_DEPTH_8U, 1 );
	   cvSetImageROI( klatka, cvRect( 0, 0,
	parzysty.width, parzysty.height ));
	   cvCvtColor(klatka, szary, CV_BGR2GRAY);
	   cvPyrDown( szary, maly, 7 );
	   cvPyrUp( maly, szary, 7 );
	   CvMemStorage* storage =
	cvCreateMemStorage(0);

	   // zmiana w stosunku do kodu
	//wykorzystuj¹cego funkcjê cvHoughLines2 --
	//obraz jest przygotowany za pomoc¹ filtra Gaussa
	   cvSmooth(szary, szary, CV_GAUSSIAN, 9,
	9);
	   // wykrywanie okrêgów
	   CvSeq* circles = cvHoughCircles(szary,
	storage, CV_HOUGH_GRADIENT, 2, szary->height/4, 200, 100);
	   // wykreœlanie wykrytych okrêgów na obrazie Ÿród³owym
	   int i;
	   for (i = 0; i < circles->total; i++)
	   {
	   float* p = (float*)cvGetSeqElem( circles, i
	);
	   cvCircle( klatka, cvPoint(cvRound(p[0]),cvRound(p[1])), cvRound(p[2]),
			   CV_RGB(255,0,0), 3, 8, 0 );
	   }
	   cvShowImage( "okienko", klatka );
	   cvReleaseImage( &maly );
	   cvReleaseImage( &szary );
	   if ( ( cvWaitKey(10) & 255 ) == 27 )
	break;
	   }
	  cvReleaseCapture( &obraz );
	  cvDestroyWindow( "okienko" );



}

void showLines()
{
	  CvCapture* obraz = cvCaptureFromCAM (CV_CAP_ANY);
	  if ( !obraz ) {
	   fprintf( stderr, "Brak kamery\n" );
	   return ;
	   }
	  cvNamedWindow( "okienko", CV_WINDOW_AUTOSIZE );
	  CvSize parzysty;
	  while ( 1 ) {
	   IplImage* klatka = cvQueryFrame( obraz );
	   if ( !klatka ) {
	    fprintf( stderr, "Brak klatki\n" );
	    break;
	    }
	   // skalowanie obrazu
	   parzysty = cvSize( klatka->width & -2,
	klatka->height & -2 );
	   IplImage* szary = cvCreateImage(
	parzysty, IPL_DEPTH_8U, 1 );
	   IplImage* maly = cvCreateImage(
	cvSize(parzysty.width/2, parzysty.height/2),
	IPL_DEPTH_8U, 1 );
	   cvSetImageROI( klatka, cvRect( 0, 0,
	parzysty.width, parzysty.height ));
	   cvCvtColor(klatka, szary, CV_BGR2GRAY);
	   cvPyrDown( szary, maly, 7 );
	   cvPyrUp( maly, szary, 7 );
	   // wykrywanie krawêdzi algorytmem Canny
	   IplImage* koncowy = cvCreateImage(
	parzysty, 8, 1 );
	   cvCanny( szary, koncowy, 75, 150, 3 );
	   cvDilate( koncowy, koncowy, 0, 1 );
	   // przygotowanie zmiennych przechowuj¹cych dane linii
	   CvMemStorage* storage =
	cvCreateMemStorage(0);
	   CvSeq* linie = 0;
	   // transformacja Hougha
	   linie = cvHoughLines2(koncowy, storage,
	CV_HOUGH_PROBABILISTIC, 1, CV_PI/180, 50, 50,
	10 );
	   // wykreœlanie linii na obrazie Ÿród³owym
	   for (int i = 0; i < linie->total; i++ )
	    {
	    CvPoint* linia = (CvPoint*)
	cvGetSeqElem(linie,i);
	    cvLine(klatka, linia[0], linia[1], CV_RGB(255,0,0), 3, 8 );
	    }
	   cvShowImage( "okienko", klatka );
	   // porz¹dki
	   cvReleaseImage( &maly );
	   cvReleaseImage( &szary );
	   cvReleaseImage( &koncowy );
	   if ( ( cvWaitKey(10) & 255 ) == 27 )
	break;
	   }
	  cvReleaseCapture( &obraz );
	  cvDestroyWindow( "okienko" );
}


// zmodyfikowana wersja demo "Square Detector"
// oblicza cosinus k¹ta, umo¿liwiaj¹c odnalezienie k¹tów prostych
double angle( CvPoint* pt1, CvPoint* pt2,
CvPoint* pt0 )
  {
  double dx1 = pt1->x - pt0->x;
  double dy1 = pt1->y - pt0->y;
  double dx2 = pt2->x - pt0->x;
  double dy2 = pt2->y - pt0->y;
  return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 +
dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
  }

void showSquares()
{

	  CvCapture* obraz = cvCaptureFromCAM (CV_CAP_ANY);
	  if ( !obraz ) {
	   fprintf( stderr, "Brak kamery\n" );
	   return ;
	   }
	  CvSize parzysty;
	  int rozmiary_klatki =
			  (int)(cvGetCaptureProperty(obraz, CV_CAP_PROP_FRAME_WIDTH) * cvGetCaptureProperty(obraz,

	CV_CAP_PROP_FRAME_HEIGHT) );
	  cvNamedWindow( "okienko", CV_WINDOW_AUTOSIZE );
	  CvSeq* prostokaty;
	  while ( 1 ) {
	   IplImage* klatka = cvQueryFrame( obraz );
	   if ( !klatka ) {
	    fprintf( stderr, "Brak klatki\n" );
	    break;
	    }

	   parzysty = cvSize( klatka->width & -2,
	klatka->height & -2 );
	   IplImage* szary = cvCreateImage(
	parzysty, IPL_DEPTH_8U, 1 );
	   IplImage* maly = cvCreateImage(
	cvSize(parzysty.width/2, parzysty.height/2),
	IPL_DEPTH_8U, 1 );
	   cvSetImageROI( klatka, cvRect( 0, 0,
	parzysty.width, parzysty.height ));
	   cvCvtColor(klatka, szary, CV_BGR2GRAY);
	   cvPyrDown( szary, maly, 7 );
	   cvPyrUp( maly, szary, 7 );
	   IplImage* koncowy = cvCreateImage(
	parzysty, 8, 1 );
	   // deklaracje zmiennych przechowuj¹cych
	//kontury oraz prostok¹ty
	   CvSeq* kontury;
	   CvPoint* rect;
	   CvMemStorage* storage = 0;
	   // przygotowanie obrazu; binaryzacja,
	//wykrywanie krawêdzi
	   int l, N = 11;
	   for( l = 0; l < N; l++ )
	    {
	    if( l == 0 )
	    {
	    // wykrywanie krawêdzi za pomoc¹ algorytmu Canny
	    cvCanny( szary, koncowy, 0, 50, 5 );
	    cvDilate( koncowy, koncowy, 0, 1 );
	    }
	   else
	    {
	    // binaryzacja metod¹ progowania
	    cvThreshold( szary, koncowy,
	(l+1)*255/N, 255, CV_THRESH_BINARY );
	    }
	    // wykrywanie konturów na przygotowanym  wczeœniej obrazie
	    storage = cvCreateMemStorage(0);
	    cvFindContours(koncowy, storage,
	 &kontury, sizeof(CvContour), CV_RETR_LIST,
	 CV_CHAIN_APPROX_SIMPLE );
	    // dodatkowe deklaracje
	    double powierzchnia_max = 0.0;
	    CvPoint pt[4];
	    prostokaty = cvCreateSeq( 0,
	 sizeof(CvSeq), sizeof(CvPoint), storage );
	    CvSeq* rezultat;
	    double s, t;
	    int i;
	    while( kontury )
	     {
	     rezultat = cvApproxPoly( kontury,
	 sizeof(CvContour), storage, CV_POLY_APPROX_DP, cvContourPerimeter(kontury)*0.02, 0 );
	     // poszukiwanie konturów o czterech
	 //wierzcho³kach, o powierzchni wiêkszej od
	 //minimalnej dozwolonej (aby usun¹æ artefakty)
	     // oraz mniejszej od ca³ej powierzchni klatki
	     if( rezultat->total == 4 &&
	     fabs(cvContourArea(rezultat,CV_WHOLE_SEQ)) > 1000 &&
	     cvCheckContourConvexity(rezultat) &&
	 (fabs(cvContourArea(rezultat,CV_WHOLE_SEQ)) <
	 ( (rozmiary_klatki / 10) * 9.5 )) )
	      {
	      s = 0;
	      for( i = 0; i < 5; i++ )
	       {
	       if( i >= 2 )
	        {
	        t = fabs(angle(
	        (CvPoint*)cvGetSeqElem( rezultat,
	 i ),
	        (CvPoint*)cvGetSeqElem( rezultat,
	 i-2 ),
	        (CvPoint*)cvGetSeqElem( rezultat,
	 i-1 )));
	        s = s > t ? s : t;
	        }
	       }
	      // cosinus k¹tów bliski zeru, a wiêc  kontur jest prostok¹tem
	      if( s < 0.2 )
	       {
	       for( i = 0; i < 4; i++ ) cvSeqPush(
	 prostokaty, (CvPoint*)cvGetSeqElem( rezultat,
	 i ));
	       // wykryty prostok¹t jest  najwiêkszym z widocznych na ekranie

	       if ( fabs(cvContourArea(rezultat,CV_WHOLE_SEQ)) > powierzchnia_max )
	        {
	        powierzchnia_max =
	 fabs(cvContourArea(rezultat,CV_WHOLE_SEQ));
	        CvSeqReader reader;
	        cvStartReadSeq( rezultat, &reader,
	 0 );
	        for( int ii = 0; ii < rezultat->total; ii += 4 )
	         {
	         rect = pt;
	                 memcpy( pt, reader.ptr,
	 prostokaty->elem_size );
	         CV_NEXT_SEQ_ELEM( rezultat->elem_size, reader );
	         memcpy( pt + 1, reader.ptr,
	 rezultat->elem_size );
	         CV_NEXT_SEQ_ELEM( rezultat->elem_size, reader );
	         memcpy( pt + 2, reader.ptr,
	 rezultat->elem_size );
	         CV_NEXT_SEQ_ELEM( rezultat->elem_size, reader );
	         memcpy( pt + 3, reader.ptr,
	 rezultat->elem_size );
	         CV_NEXT_SEQ_ELEM( rezultat->elem_size, reader );
	         }
	        }
	       }
	      }
	     // przejœcie do kolejnego konturu
	     kontury = kontury->h_next;
	     }
	    // wykreœlenie prostok¹ta na obrazie Ÿród³owym
	    if ( klatka &&  rect )
	     {
	     int counting = 4;
	     cvPolyLine( klatka, &rect, &counting,
	 1, 1, CV_RGB(0,255,0), 3, 8 );
	     }
	    }
	    cvShowImage( "okienko", klatka );
	    cvReleaseImage( &maly );
	    cvReleaseImage( &szary );
	    cvReleaseImage( &koncowy );
	    if ( ( cvWaitKey(10) & 255 ) == 27 )
	 break;
	    }
	   cvReleaseCapture( &obraz );
	   cvDestroyWindow( "okienko" );
}

char askUserForChoice()
{
	printf("OpenCVStudy. Program pobiera obraz z kamerki i wszukuje figury geometryczne\n");
	printf("1 - Linie\n");
	printf("2 - Okregi\n");
	printf("3 - Prostokaty\n");
	printf("Wybierz, czego program ma szukac: ");
	char choice = '\0';
	scanf("%c", &choice);
	return choice;
}

int main()
{
	const char choice = askUserForChoice();
	switch (choice) {
		case '1' :
			showLines();
			break;
		case '2' :
			showCircles();
			break;
		case '3' :
			showSquares();
			break;
		default :
			printf("Zly wybor!\nPress any key...");
			getchar();
			getchar();
	}

	return 0;
}


