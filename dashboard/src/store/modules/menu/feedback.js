import lazyLoading from './lazyLoading'

export default {
  name: 'Feedback',
  path: '/feedback',
  component: lazyLoading('feedback/Feedback'),
  meta: {
    default: true,
    title: 'menu.feedback',
    iconClass: 'vuestic-icon vuestic-icon-comments'
  }
}
