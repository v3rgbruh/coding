from django.urls import path
from base.views import user_views as views

urlpatterns = [
    path('login/', views.MyTokenObtainPairView.as_view(),
         name='token_obtain_pair'),
    path('', views.get_users, name='users'),
    path('update/<str:pk>/', views.update_user_by_id, name='update'),
    path('delete/<str:pk>/', views.delete_user, name='delete'),
    path('register/', views.create_user, name='register'),
    path('profile/', views.get_user_profile, name='users-profile'),
    path('profile/update/', views.update_user_profile,
         name='user-profile-update'),

    path('<str:pk>/', views.get_user_by_id, name='user'),
]
