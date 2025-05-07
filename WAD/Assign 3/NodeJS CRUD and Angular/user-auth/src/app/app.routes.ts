import { Routes , RouterModule } from '@angular/router';
import { NgModule } from '@angular/core';
import { RegisterComponent } from './register/register.component';
import { LoginComponent } from './login/login.component';
import { ProfileComponent } from './profile/profile.component';
import { BrowserModule } from '@angular/platform-browser';
import { FormsModule } from '@angular/forms';

export const routes: Routes = [
    { path: '', component: RegisterComponent },
    { path: 'login', component: LoginComponent },
    { path: 'profile', component: ProfileComponent },
];

@NgModule({
    imports: [RouterModule.forRoot(routes) , BrowserModule , FormsModule],
    exports: [RouterModule]
  })
export class AppRoutingModule { }
